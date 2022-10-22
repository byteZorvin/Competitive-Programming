# Write your MySQL query statement below
SELECT name 
FROM salesPerson 
WHERE salesPerson.sales_id 
NOT IN(
    SELECT sales_id
    FROM 
        (SELECT * FROM company WHERE name = 'red') redCompanies
        INNER JOIN
        orders ON redCompanies.com_id = orders.com_id
);