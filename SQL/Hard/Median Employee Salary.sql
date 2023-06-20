WITH cte as(
    SELECT
        *,
        ROW_NUMBER() OVER(
            PARTITION BY company
            ORDER BY
                salary
        ) AS rnk,
        COUNT(*) OVER(PARTITION BY company) AS number_of_employees
    FROM
        Employee
)
SELECT
    id,
    company,
    salary
FROM
    cte
WHERE
    rnk BETWEEN number_of_employees / 2
    AND number_of_employees / 2 + 1