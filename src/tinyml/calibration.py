import math,statistics
def features(rows):
 m=[math.sqrt(x*x+y*y+z*z) for x,y,z in rows];r=math.sqrt(sum(x*x for x in m)/len(m));p=max(m);return {"rms":r,"peak":p,"crest":p/r if r else 0}
def calibrate(windows):
 f=[features(x) for x in windows];return {k:{"median":statistics.median(y[k] for y in f),"max":max(y[k] for y in f)} for k in ("rms","peak","crest")}
