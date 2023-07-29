import subprocess
import filecmp
import random

# subprocess.Popen("make cf bf gen",shell=True).wait()

while True:
    rnd = random.randint(0,100000)
    subprocess.Popen("./gen "+str(rnd)+" > input && ./cf < input > cf.out && ./bf < input > bf.out",shell=True).wait()
    try:
        status = filecmp.cmp("cf.out", "bf.out")
        if status:
            print("files are the same")
        else:
            print("files are different, seed: "+str(rnd))
            break
    except IOError:
        print("Error:"+ "File not found or failed to read")