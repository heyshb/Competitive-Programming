:loop
python gen.py > tmp.in
shb.exe < tmp.in 
lzw.exe < tmp.in
fc lzw.out shb.out
if %errorlevel%==0 goto loop
pause 