def move(n,s,i,d,c)
	if n>0
		move(n-1,s,d,i,c)
		puts "disk #{n} is moved from #{s} to #{d}."
		c+=1
		move(n-1,i,s,d,c)
		# puts c
		# raise c
	end
end

n = gets.to_i
move(n,"source tower",'intermediate tower','destination tower',0)