# md5-filex

Calculate file checksum using MD5 in node.js native (start with reading a file).

> A bit faster than md5-file.

## Installation

```sh
$ npm install --save md5-filex
```

## Usage

```javascript
const md5 = require("md5-filex");

// Async usage
md5.calculate("LICENSE.md", function(err, hash) {
    console.log(err, hash);
});

// Sync usage
const hash = md5.calculate("LICENSE.md");
console.log(hash);
```

## API

### .calculate(filename: string[, callback: function])

If no `callback` passed, it will be called synchronously, otherwise asynchronously.

## Benchmark

Compared with [md5-file](https://www.npmjs.com/package/md5-file) by using
[./benchmark/index.js](https://github.com/BoogeeDoo/node-md5-file/blob/master/benchmark/index.js).

```
md5-filex x 202 ops/sec ±0.42% (80 runs sampled)
md5-file x 183 ops/sec ±1.24% (80 runs sampled)
```

> Machine:
>   * OS: OSX
>   * CPU: 2.5 GHz Intel Core i7
>   * Memo: 16 GB 1600 MHz DDR3
>   * Disk: 500 GB SSD

### Some More Benchmarks

```
A file with 8kb:

md5-filex x 44,972 ops/sec ±0.31% (89 runs sampled)
md5-file x 33,119 ops/sec ±3.51% (81 runs sampled)
```

```
A file with 400kb:

md5-filex x 1,112 ops/sec ±0.33% (89 runs sampled)
md5-file x 1,052 ops/sec ±0.49% (88 runs sampled)
```

## Contribution

You're welcome to make pull requests!

「雖然我覺得不怎麼可能有人會關注我」
