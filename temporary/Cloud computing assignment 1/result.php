<html>
  <body>
    <?php
	/*click submit button,create a fibonacci txt and generate fibonacci series*/
	     session_start();
         if(array_key_exists("content", $_POST)){
		 $fibo = fopen('gs://s3548974-storage/fibonacci_'.$_POST['content'].'.txt','w');
		 $fib=[];
		 $fib[0] = 1;
		 $fib[1] = 1;
		 fwrite($fibo, $fib[0]." ");
		 fwrite($fibo, $fib[1]." ");
		 for ($i = 2; $i<$_POST["content"]; $i++){
			 $fib[$i] = $fib[$i-2]+$fib[$i-1];
			  fwrite($fibo, $fib[$i]." ");			  
		 } 
		 fclose($fibo);
	     }
	       /*read from file and calculate numbers, create result file*/
		       $A = $_POST['A'];
			   $B = $_POST['B'];
			   $C = $_POST['C'];
			   $fiboSum = $_POST['fibo'];
			   $length = $_POST['content'];
			   for($x = 0;$x <$_POST['content']; $x++){
		        $fiboSum += $fib[$x];//calculate the sum of fibonacci
		       }
			   $length = $_POST['count'];
			   $sum = $A+$B;
	           $total = $sum * $C +$fibosum;		
               $average = $total/(3+ $length);
               if(isset($_POST["submit_button"])){		
                echo "total: " .$total;
	            echo"<br>";
	            echo "average: ".$average;
				$result = fopen('gs://s3548974-storage/result.txt','w');
				fwrite($result,$average);
				fclose($result);
			}
     ?>
	 <form action = "" method = "post">
	 <p>A: </p>
	 <div><textarea name="A", rows = "1", cols ="20"></textarea></div>
	 <p>B: </p>
	 <div><textarea name="B", rows = "1", cols ="20"></textarea></div>
	 <p>C: </p>
	 <div><textarea name="C", rows = "1", cols ="20"></textarea></div>
	 <input type="hidden" id="fibosum" name="fibo" value="<?php echo $fiboSum ?>">
	 <input type="hidden" id="lengths" name ="length" value = "<?php echo $length ?>">
	 <input type="hidden" id="count" name ="count" value = "<?php echo htmlspecialchars($_POST['content']) ?>">
	 <div><input type= "submit"name = "submit_button" value = "submit"></div>
	 </form>
  </body>
</html>