Create database if not exists PrisonDB3;

Use PrisonDB3;

Create Table if not exists Prison3 (
    prisonerID int auto_increment not null,
    lastName varchar(30),
    firstName varchar(30),
    photo varchar(150),
    birthDate date,
    height decimal(4,2),
    hair varchar(15),
    eyes varchar(15),
    placeOfBirth varchar(30),
    sentence varchar(255),
    dateOfConviction date,
    dateToBeLiberated date,
    unique(prisonerID)
);   

insert into Prison3
values (null, 'Manson', 'Charles', 'cmanson.jpg', '1934-11-12', 5.7, 'black', 'black', 'USA', 
        'Commuted to life imprisonment without the possibility of parole', '1951-10-01', null); 
        
Select * from Prison3;