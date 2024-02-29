// This is a comment
= 
// This too
= Introduction And Short Overview 
Originally, the *prediction* model was only able to recommend the next component that should be added to *strong* the _italic_ construction, _but `adskfaks #footnote[a] ldjf` not_ where to add it. This project explores a possible modification of the preexisting architecture in order to change that. #footnote[ayo]

*a*a*a*
-*ayo*. ^
==          ayo

*hallo*
*hallo*

== Hello *the
re* haha

==
On a high level, there are two major changes. First, the new model now has another output that is tasked with predicting the node onto which the next component should be added, making it a multi-task model. Second, the component classification now happens per node, as opposed to the per graph classification that was previously done, meaning the model predicts for each node what the next component could be. The final model prediction is then determined by combining both outputs.

The following sections will detail how the dataset is created, have specifics about the architecture and briefly show the findings.

= System
The most important files are located in `enco_prediction_scripts/` and `models/enco_prediction/`, in the branch `feature/add-ext-node-pred`. #footnote[enco is an acronym for #strong[E]xtension #strong[N]ode#strong[Co]mponent]. 

== Dataset <sec:dataset>

