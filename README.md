# Node MD5 File

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

## Contribution

You're welcome to make pull requests!

「雖然我覺得不怎麼可能有人會關注我」
