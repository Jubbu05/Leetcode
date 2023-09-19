WITH cte AS(
  SELECT user_id,
  COUNT(*) AS tweet_bucket
  FROM tweets
  WHERE tweet_date BETWEEN '2022-01-01' AND '2022-12-31'
  GROUP BY 1
)
SELECT tweet_bucket,
COUNT(*) AS users_num
FROM cte
GROUP BY 1
