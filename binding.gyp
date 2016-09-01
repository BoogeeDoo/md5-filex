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
      ]
    }
  ]
}
