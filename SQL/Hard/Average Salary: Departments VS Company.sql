WITH cte AS(
    SELECT
        s.employee_id,
        s.amount,
        DATE_FORMAT(s.pay_date, '%Y-%m') AS pay_month,
        e.department_id,
        AVG(amount) OVER(PARTITION BY DATE_FORMAT(s.pay_date, '%Y-%m')) AS company_avg,
        AVG(amount) OVER(
            PARTITION BY DATE_FORMAT(s.pay_date, '%Y-%m'),
            e.department_id
        ) AS department_avg
    FROM
        Salary s
        LEFT JOIN Employee e ON s.employee_id = e.employee_id
)
SELECT
    DISTINCT pay_month,
    department_id,
    CASE
        WHEN department_avg > company_avg THEN 'higher'
        WHEN department_avg < company_avg THEN 'lower'
        ELSE 'same'
    END AS comparison
FROM
    cte