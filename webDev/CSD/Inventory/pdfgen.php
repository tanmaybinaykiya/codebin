<?php
require('fpdf.php');
$pdf = new FPDF();
//$header = array('Country', 'Capital');
//$pdf->SetFont('Arial','',14);

$pdf->AddPage();
$pdf->Cell(40,10,'Hello World!');

$file=fopen("Inventory.pdf","w");
$op=$pdf->Output();
fwrite($file, $op);
fclose($file);
?>