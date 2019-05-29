import os


def recursive(DIR):
    for files in os.listdir(DIR):

        if os.path.isdir(os.path.join(DIR,files)):
            print("\nfiles in DIR ",os.path.join(DIR,files),end= ": ")
            recursive(os.path.join(DIR,files))
        else:
            print(files,end= " ")
directory=input("enter directory path : ")
recursive(directory)
print()

