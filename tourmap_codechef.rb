require 'set'
T=gets.chomp.to_i

for i in 1..T
	N=gets.chomp.to_i
	#a=Array.new(N)

	if N==1
		temp = gets.chomp
		puts "#{temp}"
		cost=temp.split(" ")[2]
		puts "#{cost}"

	else
		a=[]
		for j in 1..N-1
			temp=gets.chomp.split(" ")
			a << temp
		end
		b=[]
		for j in 1..N-1
			b << a[j-1][0,2]
		end
		ap=Hash.new
		for j in 1..N-1
			ap[b[j-1]] = a[j-1][2]
		end
		set=[].to_set
		for j in 1..N-1
			for p in 1..2
				set << b[j-1][p-1]
			end
		end
		set_array=set.to_a
		hash=Hash[b]
		for j in 1..N
			if hash[set_array[j-1].to_s] == nil
				destination = set_array[j-1]
			end
		end
		final = []
		reversed_hash = hash.invert
		while !destination.nil?
			final << destination
			destination = reversed_hash[destination]
		end
		fr = final.reverse
		fr = final.reverse
		for j in 1..N-1
			puts "#{fr[j-1]} #{fr[j]} #{ap[fr[j-1..j]]}"
		end
		cost = ap.values
		for j in 1..N-1
			cost[j-1] = cost[j-1].chop.to_i
		end
		puts "#{cost.inject(:+)}$ \n"
	end
	

end