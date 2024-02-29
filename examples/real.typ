== Dataset <sec:dataset>
This project was only tested on the `festo_fdt` dataset. There are two steps in creating it:
- #[
    `create_enco_partial_graphs.py`: The actual creation of the partial graphs (objects of graph class specified in `preprocessing/graph.py`) with their labels (dictionary containing target node and component, objects of classes in `preprocessing/{node,component}.py`). The resulting (graph, label) tuple list is pickled and stored in `enco_festo_fdt_partial_graphs_{train,val,test}.dat`. A single (graph, label) instance looks like this:
    #code(
      lang: "Python",
      ```python
      (graph, {
        "target_node": <the target node object of the graph>,
        "target_component": <the target component object of the graph>
      })
      ```
    )
    This format was chosen so that the data is easily interpretable, even only on its own.
  ]
- #[
  `create_enco_dgl_samples.py`: Here, the graph / label pairs created earlier are converted to DGLGraph / tensor pairs, and the components at each node are translated to embeddings. All three of the converted datasets are stored in `enco_festo_fdt_NB_{embedding_size}_dgl.hdf5`. The label tensor has three entries:
  #code(
    lang: "Python",
    ```python torch.tensor([<target node index>, <graph size>, <target component index>])```
  )
  Theoretically, the graph size is redundant because it can be obtained from the graphs, but for calculating the loss in a clear way and in the usual style for PyTorch, additionally storing it in the labels was deemed better. Further information on that in @sec:calc_loss.

  ]

Overall, the preexisting files were a good basis for the new preprocessing pipeline. The most significant change compared to the old dataset is, as is probably obvious, the new data that is extracted and its new representation. But there are also smaller changes, for example a substantial speedup was achieved by using multiprocessing in the preprocessing scripts.

The created dataset as well as the partial graphs files can be found in `/cfs/share/data/kognia/paper/results_toplakle/data/`.

== Architecture <sec:arch>
#figure(
  image("forschungsmodul_model3.png", width: 70%),
  caption: "High-level view of the model architecture. Values in tensors associated with the nodes are not representative, dimensionality is."
) <fig:model>

=== Overview
@fig:model shows what the model, in essence, looks like. The input graphs are first passed through shared (or: common) layers, and after that given to the specialized task layers. The idea behind this architecture is that the model, by having two tasks, learns a better internal representation of the problem in the common layers, which then in turn benefits performance in both tasks. 

Each of these three components has their own hyperparameters, specifically _layer width_ and _number of layers_. Suitable and well-performing values were found using hyperparameter searches in Optuna, more on that in @sec:results.

There are three variations of this model, utilizing either `GCN` layers, `GAT` layers or `GATv2` layers. The last two, as the name implies, have an attention mechanism. They generally perform better, but in turn also consume more memory, especially with high numbers of attention heads.

Another addition to the original model is that after each layer, a layer norm step is performed. Directly comparing the same model with and without layer norm shows that the one that did use it performed slightly better.

=== Real-world usage <sec:real-world-usage>
The goal of this project is to, in the end, suggest the next component a user most likely needs, and where to attach it. To determine this, the two model outputs for a given graph need to be combined into a single recommendation that suggests both the location and the component. This is done in the following way:
