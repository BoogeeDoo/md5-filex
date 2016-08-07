{
  "targets": [
    {
      "target_name": "leblanc",
      "sources": [
        "./src/leblanc.cpp"
      ],
      "include_dirs": [
        "<!(node -e \"require('nan')\")"
      ]
    }
  ]
}
