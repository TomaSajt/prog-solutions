param ($path)
if($path -eq $null) {
    throw 'Please supply a path to a .cpp file'
}
if (-not (Test-Path -Path $path)) {
    throw 'The file does not exist'
}
if(-not ($path -match '.cpp')) {
    throw 'The supplied file is not a .cpp file'
}
g++ $path
./a.exe