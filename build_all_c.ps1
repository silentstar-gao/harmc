Get-ChildItem -Path . -Filter *.c | ForEach-Object {
    clang -c $_.FullName -o ($_.BaseName + ".obj")
}