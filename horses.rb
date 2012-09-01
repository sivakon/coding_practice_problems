T=gets.to_i
(1..T).each do |t|
	N=gets.to_i
	a=gets.chomp.split.collect! &:to_i
	if a.length>1
		a=a.sort
		b=Array.new
		(0..a.length-2).each do |i|
			b<<(a[i+1]-a[i])
		end
		puts b.sort[0]
		#puts a[1]-a[0]
	end
end