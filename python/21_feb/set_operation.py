herbs ={'thyme','dill','corriander'}
spice ={'cumin','chilis','corriander'}

print("elements in herbs : ",herbs)
print("elements in spice : ",spice)
#check thyme is a set of herbs or not
print("thyme" in herbs)

#RETURN THE ITEMS THAT ARE IN BOTH SETS
ele= herbs & spice
print("common elements in bet two sets",ele)

#COMBINE THE ITEMS IN BOTH SETS
print(herbs | spice)

#THE ITEMS IN SET_1 THAT AREN'T IN SET_2
print(herbs - spice)

#THE ITEMS THAT ARE IN SET_1 OR SET_2,BUT NOT BOTH
print(herbs ^ spice)
