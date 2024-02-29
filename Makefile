
default:
	@tree-sitter generate
	@tree-sitter parse --time --debug examples/example.typ

small:
	@tree-sitter generate
	@tree-sitter parse --time --debug examples/small_example.typ

big:
	@tree-sitter generate
	@tree-sitter parse --time examples/big_example.typ

headings:
	@tree-sitter generate
	@tree-sitter parse --time --debug examples/headings.typ

test:
	@tree-sitter test
