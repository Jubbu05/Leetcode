SELECT
    user_id
FROM
    texts
    LEFT JOIN emails ON texts.email_id = emails.email_id
WHERE
    signup_action = 'Confirmed'
    -- AND DATEDIFF(DAY, action_date, signup_date) = 1
    -- AND EXTRACT(DAY FROM action_date)- extract(DAY FROM signup_date) = 1 
    AND DATE(action_date) = DATE(signup_date) + 1
