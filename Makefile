
default:
	@tree-sitter generate
	@tree-sitter parse --time examples/example.typ

small:
	@tree-sitter generate
	@tree-sitter parse --time --debug examples/small_example.typ

big:
	@tree-sitter generate
	@tree-sitter parse --time --debug examples/big_example.typ

test:
	@tree-sitter test
