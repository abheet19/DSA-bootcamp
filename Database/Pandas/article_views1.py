import pandas as pd

def article_views(views: pd.DataFrame) -> pd.DataFrame:
    self_views=views[views['viewer_id'] == views['author_id']]
    sorted_unique_authors=self_views['author_id'].drop_duplicates().sort_values()
    return pd.DataFrame({'id':sorted_unique_authors })
    