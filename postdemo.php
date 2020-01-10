<?php
//Creates new record as per request
//Connect to database
    $servername = "localhost";
    $username = "root";
    $password = "";
    $dbname = "attendance_system";
 
    // Create connection
    $conn = new mysqli($servername, $username, $password, $dbname);
    // Check connection
    if ($conn->connect_error) {
        die("Database Connection failed: " . $conn->connect_error);
    }
 
    //Get current date and time
    $d = date("Y-m-d");
    //echo " Date:".$d."<BR>";
    $t = date("H:i:s");
 
    if(!empty($_GET['status']))
    {
        $status = $_GET['status'];
        
        $query="SELECT * FROM id_tag_record  WHERE id = '".$status."'";
        
            if ($result=$conn->query($query)) 
            {

                if($result!="")
                {
                    
                    while($row=$result->fetch_row())
                    {
                     


                    $sql = "INSERT IGNORE INTO logs (`Roll_Number`, Names , Profiles, Date, Time) 
                    VALUES ('".$row[1]."', '".$row[2]."', '".$row[3]."', '".$d."', '".$t."')";
                    
                    if ($conn->query($sql) === TRUE) 
                    {
                        echo "OK";
                    } 
                    
                     else 
                    {
                        echo "Error: " . $sql . "<br>" . $conn->error;
                    }        
                
                    }

            $result->close();
            
            }
}
    }
 
    $conn->close();

?>
