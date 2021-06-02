import csv
from PIL import Image
import numpy as np
with open('small.csv') as f:
    f_csv = csv.reader(f)
    ret = []
    for row in f_csv:
        tmp = []
        for ele in row:
            if (float(ele) > 0.5):
                tmp.append(255)
            else:
                tmp.append(0)
        ret.append(tmp)
    new_im = Image.fromarray(np.matrix(ret))
    new_im.show()