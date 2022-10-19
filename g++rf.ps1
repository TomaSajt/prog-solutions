param ($path)
g++ $path
if(-not $LastExitCode -eq 0) {
    Exit
}
$processOptions = @{
    FilePath = ".\a.exe"
    RedirectStandardInput = ".\input.txt"
    RedirectStandardOutput = ".\output.txt"
    RedirectStandardError = ".\error.txt"
    UseNewEnvironment = $true
}
Start-Process @processOptions