WITH cte AS(
    SELECT
        *,
        row_number() over(
            ORDER BY
                visit_date
        ) AS 'cnt',
        id - (
            row_number() over(
                ORDER BY
                    visit_date
            )
        ) AS 'grp'
    FROM
        Stadium
    WHERE
        people >= 100
)
SELECT
    id,
    visit_date,
    people
FROM
    cte
where
    grp IN(
        SELECT
            grp
        FROM
            cte
        GROUP BY
            grp
        HAVING
            count(*) >= 3
    )