import pandas as pd

def sales_analysis(sales: pd.DataFrame, product: pd.DataFrame) -> pd.DataFrame:
    df=pd.merge(sales,product,how='left',on='product_id')
    df=df[['product_name','year','price']]
    return df
    