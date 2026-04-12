-- Write your query below
select s.seller_name
from seller s
where s.seller_id not in (
    select s.seller_id
    from seller s join orders o
    on s.seller_id = o.seller_id
    where o.sale_date >= '2020-01-01' and o.sale_date <= '2020-12-31'
)
order by s.seller_name asc