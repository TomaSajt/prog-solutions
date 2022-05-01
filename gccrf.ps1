param ($path, $i='.\input.txt', $o='.\output.txt',$e='.\error.txt')
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
$processOptions = @{
    FilePath = ".\a.exe"
    RedirectStandardInput = ".\input.txt"
    RedirectStandardOutput = ".\output.txt"
    RedirectStandardError = ".\error.txt"
    UseNewEnvironment = $true
}
Start-Process @processOptions