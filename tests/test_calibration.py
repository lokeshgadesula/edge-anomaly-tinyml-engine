from tinyml.calibration import *
def test_features():assert features([(1,0,0)]*64)["rms"]==1
def test_calibration():assert calibrate([[(1,0,0)]*64,[((2),0,0)]*64])["rms"]["max"]==2
def test_budget_math():assert (64*3*4+64*4+3*4+5)<64*1024
