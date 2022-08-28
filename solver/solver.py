import subprocess

challenge = subprocess.run(
    ["./safebox"],
    input="KEY{$UpER_$ecRet_K#eY}",
    text=True,
    capture_output=True,
)

with open("flag.txt", "w") as f:
    f.write(challenge.stdout[-23:].rstrip('\r\n'))

f.close()
