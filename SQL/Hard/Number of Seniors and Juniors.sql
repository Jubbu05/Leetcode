WITH cte AS(
  SELECT
    *,
    SUM(salary) OVER(
      PARTITION BY experience
      ORDER BY
        salary ROWS BETWEEN UNBOUNDED PRECEDING
        AND CURRENT ROWS
    ) AS running_total
  FROM
    Candidates
)
SELECT
  'Senior' AS experience,
  IFNULL(COUNT(employee_id), 0) AS accepted_candidates
FROM
  cte
WHERE
  experience = 'Senior'
  AND running_total <= 70000
UNION
SELECT
  'Junior' AS experience,
  IFNULL(COUNT(employee_id), 0) AS accepted_candidates
FROM
  cte
WHERE
  experience = 'Junior'
  AND running_total <= 70000 - IFNULL(
    (
      SELECT
        MAX(running_total)
      FROM
        cte
      WHERE
        experience = 'Senior'
        AND running_total <= 70000
    ),
    0
  )