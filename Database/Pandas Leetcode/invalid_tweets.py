import pandas as pd

def invalid_tweets(tweets: pd.DataFrame) -> pd.DataFrame:
    invalid_tweets_df = tweets[(tweets['content'].str.len() > 15)]
    invalid_tweet_id_df = invalid_tweets_df[['tweet_id']]
    return invalid_tweet_id_df