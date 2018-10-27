' Tee.VBS V1.02 (C) yoshioka.teruo@nifty.com 2007-04-01
' Tee.VBS copies standard input to standard output and standard error or files.
' Usage: CScript.exe //NoLogo Tee.VBS [file...] <stdin >stdout [2>stderr]

Option Explicit
Const ForWriting=2
Const ForApennding=8
Dim fso
Dim OpenMode
Dim arg
Dim Files
Dim StdIn
Dim StdOut
Dim Char

Set fso=CreateObject("Scripting.FileSystemObject")
OpenMode=ForWriting
Files=Array(fso.GetStandardStream(1))
For Each arg In WScript.Arguments
  Select Case LCase(arg)
  Case "-a","/a"
    OpenMode=ForApennding
  Case Else
    PushSet Files,fso.OpenTextFile(arg,OpenMode,True)
  End Select
Next 
If UBound(Files)=0 Then PushSet Files,fso.GetStandardStream(2) 
Set StdIn=fso.GetStandardStream(0)
Do While Not StdIn.AtEndOfStream
  Char=StdIn.Read(1)
  For Each StdOut In Files
    StdOut.Write Char
  Next
Loop
For Each StdOut In Files
  StdOut.Close
Next
WScript.Quit

Sub PushSet(Items,Item)
ReDim Preserve Items(UBound(Items)+1)
Set Items(UBound(Items))=Item
End Sub
