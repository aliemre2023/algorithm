import pandas as pd

def big_countries(world: pd.DataFrame) -> pd.DataFrame:
    new_data = pd.DataFrame(columns=["name", "population", "area"])

    for index,row in world.iterrows():
        name = row["name"]
        area = row["area"]
        population = row["population"]

        if(area >= 3000000 or population >= 25000000):
            new_data.loc[len(new_data)] = {"name":name, "area":area, "population":population}
        
    return new_data

    