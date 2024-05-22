import pandas as pd

def findHeavyAnimals(animals: pd.DataFrame) -> pd.DataFrame:
    animals = animals.sort_values(["weight"],ascending=False)
    animals = animals[animals["weight"] > 100]
    return animals[["name"]]