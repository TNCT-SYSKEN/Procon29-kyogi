@if(0)==(0) ECHO OFF
CScript.exe //NoLogo //E:JScript "%~f0" %*
GOTO :EOF
@end
// Tee.JS V1.02 (C) yoshioka.teruo@nifty.com 2007-04-01
// Tee.JS copies standard input to standard output and standard error or files.
// Usage: CScript.exe //NoLogo Tee.JS [file...] <stdin >stdout [2>stderr]

var ForWriting=2
var ForApennding=8

var fso=new ActiveXObject("Scripting.FileSystemObject");
var OpenMode=ForWriting;
var Files=new Array(fso.GetStandardStream(1));
for(var e=new Enumerator(WScript.Arguments);!e.atEnd();e.moveNext()){
  var arg=e.item();
  switch(arg.toLowerCase()){
  case "-a":
  case "/a":
    OpenMode=ForApennding;
    break;
  default:
    Files.push(fso.OpenTextFile(arg,OpenMode,true));
  }
} 
if(Files.length==1) Files.push(fso.GetStandardStream(2));
var StdIn=fso.GetStandardStream(0);
while(!StdIn.AtEndOfStream){
  var Char=StdIn.Read(1);
  for(var k in Files) Files[k].Write(Char);
}
for(var k in Files) Files[k].Close();
WScript.Quit();
