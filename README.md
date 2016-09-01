# md5-filex

[![Version](http://img.shields.io/npm/v/md5-filex.svg)](https://www.npmjs.com/package/md5-filex)
[![Downloads](http://img.shields.io/npm/dm/md5-filex.svg)](https://www.npmjs.com/package/md5-filex)
[![License](https://img.shields.io/npm/l/md5-filex.svg?style=flat)](https://opensource.org/licenses/MIT)
[![AppVeypr](https://ci.appveyor.com/api/projects/status/90hcbf6p42ee34dk/branch/master?svg=true)](https://ci.appveyor.com/project/XadillaX/md5-filex)
[![TravisCI](https://travis-ci.org/BoogeeDoo/md5-filex.svg)](https://travis-ci.org/BoogeeDoo/md5-filex)
[![Dependency](https://david-dm.org/BoogeeDoo/md5-filex.svg)](https://david-dm.org/BoogeeDoo/md5-filex)

Calculate file checksum using MD5 in node.js native (start with reading a file).

> A bit faster than md5-file under *NIX.

## Installation

```sh
$ npm install --save md5-filex
```

## Usage

```javascript
cmd5-filext md5 = require("md5-filex");

// Async usage
md5.calculate("LICENSE.md", function(err, hash) {
    cmd5-filexole.log(err, hash);
});

// Sync usage
cmd5-filext hash = md5.calculate("LICENSE.md");
cmd5-filexole.log(hash);
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

> **HINT:** Not that fast under Microsoft Windows.

## Contribution

You're welcome to make pull requests!

「雖然我覺得不怎麼可能有人會關注我」
