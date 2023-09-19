WITH cte AS(
SELECT *,
RANK() OVER(PARTITION BY user_id ORDER BY transaction_date) AS rnk
FROM transactions
)
SELECT user_id, spend, transaction_date
FROM cte
WHERE rnk = 3