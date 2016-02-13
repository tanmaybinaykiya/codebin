
class Header extends React.Component {
	render(){
		return (
			<div className='header'>
				<div className='justForCentering'>
					<div className='headerText'>
						<span><a id='homeLink' href='#'>Vacation</a></span>
						<span>Easiest way to shop for travel </span>
					</div>
					<div id='logo'></div>
				</div>
			</div>
		);
	}
}

class RadioForm extends React.Component{

	constructor(props) {
        super(props);
        var defaultValue = null;
		var isDefault = false;
		console.log('RadioForm::', this);
		this.props.options.map((opt) => {
			if((!!opt.isDefault) && !isDefault){
				defaultValue=opt.value;
			}
		});
		this.state = {value:defaultValue};
    }

	onChangeHandler(obj){
		console.log('onChangeHandler');
		this.setState({
			value: obj.target.value
		});  
	}

	render(){
		console.log('RadioForm::render::this::', this);
		return (
			<div id='radio-form' className='subForm'>
				<span id='form-question'>{this.props.msg}</span>
				{
					this.props.options.map((opt) => 
						<div className='input-span' key={opt.value}>
							<input type='radio' name='activities' checked={opt.value === this.state.value} value={opt.value} onChange={this.onChangeHandler.bind(this)} />
							<span>{opt.name}</span>
						</div>
					)
				}
			</div>
		);
	}
}

class SelectForm extends React.Component{

	constructor(props) {
        super(props);
        var defaultValue = null, defaultName=null;
		var isDefault = false;
		this.props.options.map((opt) => {
			if((!!opt.isDefault) && !isDefault){
				defaultValue=opt.value;
				defaultName= opt.name
			}
		});

		this.state={
			value: defaultValue,
			name: defaultName
		};  
    }
	
	onChangeHandler(val, nam, self){
		return function(obj){
			console.log('onChangeHandler, this:', self, ' obj:', obj, 'val: ', val, 'name:', name);
			self.setState({
				value: val,
				name: nam
			});
		}
	}

	render(){
		console.log('SelectForm::render::this:', this);
		return (
			<div id='selectForm' className='subForm'>
				<span id='form-question'>{this.props.msg}</span>
				<div id='dropdown-content'>
					{
						<div className='selectForm-item' id='selectForm-item-default' >
							<a>{this.state.name}</a>
						</div>
					}
					<div id='selectForm-dropdown-content'>
						{
							this.props.options.map(function(opt){ 
								if(opt.value!=this.state.value){
									return(
										<div className='selectForm-item' onClick={this.onChangeHandler(opt.value, opt.name, this)}>
											<a>{opt.name}</a>
										</div>
									);
								}
							}, this)
						}
				  	</div>
			  	</div>
			</div>
		);
	}
}
class NanaPage extends React.Component{
	render(){
		return (
			<div className='nanaPage'></div>
		);
	}
}

class Footer extends React.Component{
	render(){
		return (
			<div className='footer'></div>
		);
	}
};

class FormCard extends React.Component{
	constructor(props) {
        super(props);
    }

	submitHandler(obj){
		console.log('SubmitHandler::obj::', obj, 'this:', this);
	}

	render(){
		return (
			<div className='formCard'>
				<form>
					<SelectForm />
					<RadioForm />
					<div className='subForm'>
						<p id='submitButton' onClick={this.submitHandler.bind(this)}>Lets Get Started</p>
					</div>
				</form>
			</div>
		);
	}
}
class QuestionCard extends React.Component{
	render(){
		return(
			<div id='questionCard'>
				<div id='questionCardTitle'><span>Tell us about your trip</span></div>
				<FormCard />
			</div>
		);
	}
}

class HomePage extends React.Component{
	render(){
		return (
		<div className='homePage'>
			<div id='welcomeText'><span>Find all you will need on your trip, faster, with Vacation</span></div>
			<QuestionCard />
		</div>
		);
	}
}

class Wrapper extends React.Component{
	constructor(props) {
        super(props);
        this.state  = {page: props.page};
    }

    render() {
		switch(this.state.page) {
		case 'lala':
			return (
				<div id='wrapper'>
					<Header />
					<HomePage />
					<Footer />
				</div>
			);
			break;
		case 'nana':
			return (
				<div id='wrapper'>
					<Header />
					<NanaPage />
					<Footer />
				</div>
			);
			break;
		default:
			return (
				<div id='wrapper'>
					<Header />
					<HomePage />
					<Footer />
				</div>
			);
		}
	}
}

SelectForm.defaultProps = {
	msg: 'Which place are you visiting ?' ,
	options:[{	
				name:'Barcelona',
				value:'BAR'
			}, {
				name:'Leh/Ladakh',
				value:'LEH',
				isDefault: true
			}, {
				name:'Leh2/Ladakh',
				value:'LEH2',
			}, {
				name:'Leh3/Ladakh',
				value:'LEH3',
			}, {
				name:'Leh4/Ladakh',
				value:'LEH4',
			}, {
				name:'Goa',
				value:'GOA'
			}] 
};			

RadioForm.defaultProps = { 
	msg: 'What are the activities you are looking forward to?',
	options:[{
				name:'Business',
				value:'BSNS',
			}, {
				name:'Swimming/Beach',
				value:'SWIM'
			}, {
				name:'Hiking/Trek',
				value:'HIKE',
				isDefault: true
			}, {
				name:'Clubbing',
				value:'CLUB'
			}, {
				name:'Sightseeing',
				value:'SIGT'
			}] 
};

Wrapper.defaultProps = { page: 'lala'};

ReactDOM.render(<Wrapper />, document.getElementById('content'));
