{
  "targets": [
    {
      "target_name": "leblanc",
      "sources": [
        "./src/leblanc.cpp",
        "./src/calculate.cpp"
      ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ],
      "cflags_cc!": [ "-fno-exceptions", "-pthread", "-Wl,--no-as-needed", "-ldl" ],
      "cflags_cc": [ "-Wno-ignored-qualifiers" ],
      "cflags": [ "-std=c++11" ],

      "conditions": [
        ["OS==\"win\"", {
          "sources": [
            "./src/md5_windows.c"
          ]
        }]
      ]
    }
  ]
}
