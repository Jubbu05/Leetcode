WITH cte AS(
    SELECT
        transactions_id,
        DATE_FORMTE(day, '%Y-%m') AS day,
        amount
    FROM
        Transactions
),
cte2 AS(
    SELECT
        *,
        MAX(amount) OVER(PARTITION BY day) AS max_amount
    FROM
        cte
)
SELECT
    transactions_id
FROM
    cte2
WHERE
    amount = max_amount
ORDER BY
    transactions_id