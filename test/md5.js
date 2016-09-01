/**
 * XadillaX created at 2016-09-01 15:04:09 With ♥
 *
 * Copyright (c) 2016 Souche.com, all rights
 * reserved.
 */
"use strict";

const fs = require("fs");
const path = require("path");

const md5File = require("md5-file");
const should = require("should");

const md5 = require("../md5");

const filenames = [];

function loadFilename(directory) {
    const files = fs.readdirSync(directory);
    files.forEach(filename => {
        if(filename === ".git" || filename === "node_modules") return;
        const name = path.resolve(directory, filename);
        const stat = fs.statSync(name);
        if(stat.isFile()) {
            filenames.push(name);
        } else if(stat.isDirectory()) {
            loadFilename(name);
        }
    });
}

loadFilename(path.resolve(__dirname, ".."));

describe("calculate md5", function() {
    filenames.forEach(filename => {
        describe(`calculate ${filename}`, function() {
            const right = md5File.sync(filename);

            it("sync should be right", function() {
                const res1 = md5.calculate(filename);
                right.should.equal(res1);
            });

            it("async should be right", function(done) {
                let callbacked = false;
                md5.calculate(filename, function(err, md5) {
                    callbacked = true;
                    should.ifError(err);
                    md5.should.equal(right);
                    done();
                });
                callbacked.should.equal(false);
            });

            it("sync should throw error", function() {
                try {
                    md5.calculate(filename + "!");
                } catch(e) {
                    return e.message.indexOf("can't be opened.").should.above(-1);
                }

                (1).should.equal(0);
            });

            it("async should throw error", function(done) {
                let callbacked = false;
                md5.calculate(filename + "!", function(err) {
                    callbacked = true;
                    err.message.indexOf("can't be opened.").should.above(-1);
                    done();
                });
                callbacked.should.equal(false);
            });
        });
        return;
    });
});
