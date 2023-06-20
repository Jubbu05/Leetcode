WITH cte AS(
    SELECT
        pu.invoice_id,
        SUM(pu.qunatity * po.price) AS total_price
    FROM
        Purchases pu
        LEFT JOIN Products po ON pu.product_id = po.product_id
    GROUP BY
        pu.invoice_id
    ORDER BY
        total_price DESC,
        pu.invoice_id ASC
    LIMIT
        1
)
SELECT
    pu.invoice_id,
    pu.product_name,
    pu.qunatity * po.price AS qunatity
FROM
    Purchases pu
    LEFT JOIN Products po ON pu.product_id = po.product_id
WHERE
    pu.invoice_id IN(
        SELECT
            invoice_id
        FROM
            cte
    )