param ($path)
g++ $path
if(-not $LastExitCode -eq 0) {
    Exit
}
./a.exe