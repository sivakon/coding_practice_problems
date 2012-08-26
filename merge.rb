
def sort_count_inv(a,n)
	b = []
	c = []
	d = []
	x,y,z=0,0,0
	if n==1
		# puts "#{a} in this thing"
		return a,0
	else
		puts "#{a[0..(n/2)-1]} is the first half & #{a[n/2 .. n]} is second half."
		b,x=sort_count_inv a[0..(n/2)-1],n/2
		c,y=sort_count_inv a[n/2 .. n],n-(n/2)
		d,z=merge_count_split b,c,n
		return d,x+y+z
	end
	# x = count_inv(a,n/2)
end
def merge_count_split(b,c,n)
	d = Array.new
	
	counter=0
	puts b.inspect
	puts c.inspect
	# puts b
	i,j=0,0
	# puts "this is i #{c[0]}"
	for k in 0..n-1
		puts "blah"
		if (b[i].to_i < c[j].to_i)
			d[k]=b[i]
			puts "aaaaa"
			i+=1
		elsif (b[i].to_i > c[j].to_i)
			if j<c.length
				d[k]=c[j]
				puts "bbb"
				j+=1
				counter+= b.length-(i+1)	
			end
		else
		end
		k+=1
	end
	puts d.inspect
	return d,counter
end

n=gets.chomp.to_i
a=Array.new
for i in 1..n
	a.push(gets.chomp.to_i)
end
# array a
# puts "#{a}"
# puts "#{n}"
result= sort_count_inv a,n
puts result.inspect
