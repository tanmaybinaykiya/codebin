from os import walk

def ext(fileName):
    return fileName[fileName.rfind('.')+1:].lower()

f = []
for (dirpath, dirnames, filenames) in walk("/media/E/Movies"):
    f.extend(filenames)
    # break
for fileN in f:
    if ext(fileN) not in ['srt','txt','sub','png','jpg','rtf','nfo']:
        print ext(fileN),":",fileN
    else:
        print ext(fileN)