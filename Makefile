install:
	@npm install

test:
	@./node_modules/.bin/_mocha

benchmark:
	@node benchmark/index.js

.PHONY: test benchmark
