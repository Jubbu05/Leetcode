WITH cte AS {
SELECT
    customer_id,
    product_id,
    COUNT(*) AS numb_order
FROM
    Orders
GROUP BY
    customer_id,
    product_id },
    cte2 AS(
        SELECT
            *,
            FIRST_VALUE(numb_order) OVER(
                PARTITION BY customer_id
                ORDER BY
                    numb_order DESC
            ) AS most_frequentl
        FROM
            cte
        GROUP BY
            customer_id
    )
SELECT
    c.customer_id,
    c.product_id,
    p.product_name
FROM
    cte2 c
    LEFT JOIN product p ON c.product_id = p.product_id
WHERE
    c.numb_order = c.most_frequent