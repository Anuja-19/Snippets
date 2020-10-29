use std::io::{
    Write, BufRead, BufReader, Error
};
use std::fs::File;
use std::path::Path;
const FILE_NAME: &str = &"sample.txt";

fn main() -> Result<(), Error> {
    create_and_write_to_new_file(&Path::new(FILE_NAME), "hello\nworld\n!")?;
    overwrite_existing_file(&Path::new(FILE_NAME), "new text\nthat replaces\nthe old")?;
    read_file_line_at_a_time(&Path::new(FILE_NAME))?;
    Ok(())
}

fn read_file_line_at_a_time(path: &Path) -> Result<(), Error>{
    let file_handle = File::open(path)?;
    let reader = BufReader::new(file_handle);
    for line in reader.lines() {
        println!("{}", line?); // Do something with each line
    }
    Ok(())
}

fn create_and_write_to_new_file(file_name: &Path, contents: &str) -> Result<(), Error> {
    let mut file_handle = File::create(file_name)?;
    write!(file_handle, "{}", contents)?;
    Ok(())
}

fn overwrite_existing_file(file_name: &Path, contents: &str) -> Result<(), Error>{
    let mut file_handle = File::open(file_name)?;
    write!(file_handle, "{}", contents)?;
    Ok(())
}

