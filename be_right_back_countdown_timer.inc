<?
	if(!$_POST) {
		print "<div style='text-align:center;font-weight:bold;font-size:60px;'>Countdown Timer</div>
			<form action=\"$_SERVER[PHP_SELF]\" method=\"POST\">
			<!-- input type='submit' name='submit' value=' 0.1 0 ' class=black9bold -->
			<input type='submit' name='submit' value=' 5 minutes ' class=black9bold>
			&nbsp;	
			<input type='submit' name='submit' value=' 10 minutes ' class=black9bold>
			&nbsp;
                        <input type='submit' name='submit' value=' 15 minutes ' class=black9bold>
			&nbsp;
                        <input type='submit' name='submit' value=' 30 minutes ' class=black9bold>
			&nbsp;
                        <input type='submit' name='submit' value=' 1 hour ' class=black9bold>
			</form>
			";

	} else {
		$startime = time();
		if($_POST[submit]) {
			list($d,$junk) = explode(' ',trim($_POST[submit]));
			$duration = $d;
		} else {
			# set to 5 minutes by default
			$duration = 5;
		}
		$timeleft = $starttime + ($duration * 60) + 1;

		if($d == 1) {
			$min_left = 60;
		} else {
			$min_left = date("i",$timeleft);
		}
		$sec_left = date("s",$timeleft);

		#print "min: $min_left sec: $sec_left"; exit;

                print "<script type='text/javascript'>
                        var sec = $sec_left;   // set the seconds
                        var min = $min_left;   // set the minutes

                	function countDown() {
                        	sec--;
                        	if (sec == -01) {
                                	sec = 59;
                                	min = min - 1;
                        	} else {
                                	min = min;
                        	}
				if (sec<1 && min<1) { 
					time = \"<div style='text-align:center;font-weight:bold;font-size:70px;'>Time to continue!</div><p><a href='$_SERVER[PHP_SELF]' class=bbz>Cancel</a>\"; 
				} else {
                        		if (sec<=9) { sec = \"0\" + sec; }
                                		time = \"<div style='text-align:center;font-weight:bold;font-size:58px;'>We are now on break.</div><div style='text-align:center;font-weight:bold;font-size:32px;'>Time Remaining:</div><div style='text-align:center;font-weight:bold;font-size:100px;'>\" + (min<=9 ? \"0\" + min : min) + \":\" + sec + \"</div><a href='$_SERVER[PHP_SELF]' class=bbz>Cancel</a>\";
				}
                        	if (document.getElementById) { theTime.innerHTML = time; }
                        	SD=window.setTimeout(\"countDown();\", 1000);
                        	if (min == '00' && sec == '00') { sec = \"00\"; window.clearTimeout(SD); }
                	}

                	function addLoadEvent(func) {
                        	var oldonload = window.onload;
                        	if (typeof window.onload != 'function') {
                                	window.onload = func;
                        	} else {
                                	window.onload = function() {
                                	if (oldonload) {
                                        	oldonload();
                                	}
                                	func();
                                	}
                        	}
                	}

                	addLoadEvent(function() {
                        	countDown();
                	});
                	</script>
			<span id='theTime' class='timeClass'>
                	";

	}
?>
