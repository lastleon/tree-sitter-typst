
default:
	@tree-sitter generate
	@tree-sitter parse --time example.typ

test:
	@tree-sitter test
